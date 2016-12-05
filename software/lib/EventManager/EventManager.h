/*
 * EventManager.h
 *

 * An event handling system for Arduino.
 *
 * Author: igormt@alumni.caltech.edu
 * Copyright (c) 2013 Igor Mikolic-Torreira
 *
 * Inspired by and adapted from the
 * Arduino Event System library by
 * Author: mromani@ottotecnica.com
 * Copyright (c) 2010 OTTOTECNICA Italy
 *
 * This library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser
 * General Public License as published by the Free Software
 * Foundation; either version 2.1 of the License, or (at
 * your option) any later version.
 *
 * This library is distributed in the hope that it will
 * be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser
 * General Public License along with this library; if not,
 * write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */


#ifndef EventManager_h
#define EventManager_h

#include <Arduino.h>

// Size of the listener list.  Adjust as appropriate for your application.
// Requires a total of sizeof(*f())+sizeof(int)+sizeof(boolean) bytes of RAM for each unit of size
#ifndef EVENTMANAGER_LISTENER_LIST_SIZE
#define EVENTMANAGER_LISTENER_LIST_SIZE		16
#endif

// Size of the event two queues.  Adjust as appropriate for your application.
// Requires a total of 4 * sizeof(int) bytes of RAM for each unit of size
#ifndef EVENTMANAGER_EVENT_QUEUE_SIZE
#define EVENTMANAGER_EVENT_QUEUE_SIZE		8
#endif

//#define EVENTMANAGER_DEBUG 1


class EventManager
{

public:

    // Type for an event listener (a.k.a. callback) function
    typedef void ( *EventListener )( int eventCode, String* eventParam );

    // EventManager recognizes two kinds of events.  By default, events are
    // are queued as low priority, but these constants can be used to explicitly
    // set the priority when queueing events
    //
    // NOTE high priority events are always handled before any low priority events.
    enum EventPriority { kHighPriority, kLowPriority };

    // Various pre-defined event type codes.  These are completely optional and
    // provided for convenience.  Any integer value can be used as an event code.
    enum EventType
    {
        // No event occurred; param: none
        kEventNone = 200,

        // From GPS
        kEventNewGPSCoordinate,

        // From WIFI
        kEventWifiConnected,

        // From System
        kEventNewMemoryMeasurement,
        kEventLowMemoryWarning
    };


    // Create an event manager
    // It always operates in interrupt safe mode, allowing you to queue events from interrupt handlers
    EventManager();

    // Add a listener
    // Returns true if the listener is successfully installed, false otherwise (e.g. the dispatch table is full)
    boolean addListener( int eventCode, EventListener listener );

    // Remove (event, listener) pair (all occurrences)
    // Other listeners with the same function or event code will not be affected
    boolean removeListener( int eventCode, EventListener listener );

    // Remove all occurrances of a listener
    // Removes this listener regardless of the event code; returns number removed
    // Useful when one listener handles many different events
    int removeListener( EventListener listener );

    // Enable or disable a listener
    // Return true if the listener was successfully enabled or disabled, false if the listener was not found
    boolean enableListener( int eventCode, EventListener listener, boolean enable );

    // Returns the current enabled/disabled state of the (eventCode, listener) combo
    boolean isListenerEnabled( int eventCode, EventListener listener );

    // The default listener is a callback function that is called when an event with no listener is processed
    // These functions set, clear, and enable/disable the default listener
    boolean setDefaultListener( EventListener listener );
    void removeDefaultListener();
    void enableDefaultListener( boolean enable );

    // Is the ListenerList empty?
    boolean isListenerListEmpty();

    // Is the ListenerList full?
    boolean isListenerListFull();

    int numListeners();

    // Returns true if no events are in the queue
    boolean isEventQueueEmpty( EventPriority pri = kLowPriority );

    // Returns true if no more events can be inserted into the queue
    boolean isEventQueueFull( EventPriority pri = kLowPriority );

    // Actual number of events in queue
    int getNumEventsInQueue( EventPriority pri = kLowPriority );

    // tries to insert an event into the queue;
    // returns true if successful, false if the
    // queue if full and the event cannot be inserted
    boolean queueEvent( int eventCode, String* eventParam, EventPriority pri = kLowPriority );

    // this must be called regularly (usually by calling it inside the loop() function)
    int processEvent();

    // this function can be called to process ALL events in the queue
    // WARNING:  if interrupts are adding events as fast as they are being processed
    // this function might never return.  YOU HAVE BEEN WARNED.
    int processAllEvents();


private:

    // EventQueue class used internally by EventManager
    class EventQueue
    {

    public:

        // Queue constructor
        EventQueue();

        // Returns true if no events are in the queue
        boolean isEmpty();

        // Returns true if no more events can be inserted into the queue
        boolean isFull();

        // Actual number of events in queue
        int getNumEvents();

        // Tries to insert an event into the queue;
        // Returns true if successful, false if the queue if full and the event cannot be inserted
        //
        // NOTE: if EventManager is instantiated in interrupt safe mode, this function can be called
        // from interrupt handlers.  This is the ONLY EventManager function that can be called from
        // an interrupt.
        boolean queueEvent( int eventCode, String* eventParam );

        // Tries to extract an event from the queue;
        // Returns true if successful, false if the queue is empty (the parameteres are not touched in this case)
        boolean popEvent( int* eventCode, String** eventParam );

    private:

        // Event queue size.
        // The maximum number of events the queue can hold is kEventQueueSize
        // Increasing this number will consume 2 * sizeof(int) bytes of RAM for each unit.
        static const int kEventQueueSize = EVENTMANAGER_EVENT_QUEUE_SIZE;

        struct EventElement
        {
            int code;	// each event is represented by an integer code
            String* param;  // each event has a single integer parameter
        };

        // The event queue
        EventElement mEventQueue[ kEventQueueSize ];

        // Index of event queue head
        int mEventQueueHead;

        // Index of event queue tail
        int mEventQueueTail;

        // Actual number of events in queue
        int mNumEvents;
    };


    // ListenerList class used internally by EventManager
    class ListenerList
    {

    public:

        // Create an event manager
        ListenerList();

        // Add a listener
        // Returns true if the listener is successfully installed, false otherwise (e.g. the dispatch table is full)
        boolean addListener( int eventCode, EventListener listener );

        // Remove event listener pair (all occurrences)
        // Other listeners with the same function or eventCode will not be affected
        boolean removeListener( int eventCode, EventListener listener );

        // Remove all occurrances of a listener
        // Removes this listener regardless of the eventCode; returns number removed
        int removeListener( EventListener listener );

        // Enable or disable a listener
        // Return true if the listener was successfully enabled or disabled, false if the listener was not found
        boolean enableListener( int eventCode, EventListener listener, boolean enable );

        boolean isListenerEnabled( int eventCode, EventListener listener );

        // The default listener is a callback function that is called when an event with no listener is processed
        boolean setDefaultListener( EventListener listener );
        void removeDefaultListener();
        void enableDefaultListener( boolean enable );

        // Is the ListenerList empty?
        boolean isEmpty();

        // Is the ListenerList full?
        boolean isFull();

        // Send an event to the listeners; returns number of listeners that handled the event
        int sendEvent( int eventCode, String* param );

        int numListeners();

    private:

        // Maximum number of event/callback entries
        // Can be changed to save memory or allow more events to be dispatched
        static const int kMaxListeners = EVENTMANAGER_LISTENER_LIST_SIZE;

        // Actual number of event listeners
        int mNumListeners;

        // Listener structure and corresponding array
        struct ListenerItem
        {
            EventListener	callback;		// The listener function
            int				eventCode;		// The event code
            boolean			enabled;			// Each listener can be enabled or disabled
        };
        ListenerItem mListeners[ kMaxListeners ];

        // Callback function to be called for event types which have no listener
        EventListener mDefaultCallback;

        // Once set, the default callback function can be enabled or disabled
        boolean mDefaultCallbackEnabled;

        // get the current number of entries in the dispatch table
        int getNumEntries();

        // returns the array index of the specified listener or -1 if no such event/function couple is found
        int searchListeners( int eventCode, EventListener listener);
        int searchListeners( EventListener listener );
        int searchEventCode( int eventCode );

    };

    EventQueue 	mHighPriorityQueue;
    EventQueue 	mLowPriorityQueue;

    ListenerList		mListeners;
};

//*********  INLINES   EventManager::  ***********

inline boolean EventManager::addListener( int eventCode, EventListener listener )
{
    return mListeners.addListener( eventCode, listener );
}

inline boolean EventManager::removeListener( int eventCode, EventListener listener )
{
    return mListeners.removeListener( eventCode, listener );
}

inline int EventManager::removeListener( EventListener listener )
{
    return mListeners.removeListener( listener );
}

inline boolean EventManager::enableListener( int eventCode, EventListener listener, boolean enable )
{
    return mListeners.enableListener( eventCode, listener, enable );
}

inline boolean EventManager::isListenerEnabled( int eventCode, EventListener listener )
{
    return mListeners.isListenerEnabled( eventCode, listener );
}

inline boolean EventManager::setDefaultListener( EventListener listener )
{
    return mListeners.setDefaultListener( listener );
}

inline void EventManager::removeDefaultListener()
{
    mListeners.removeDefaultListener();
}

inline void EventManager::enableDefaultListener( boolean enable )
{
    mListeners.enableDefaultListener( enable );
}

inline boolean EventManager::isListenerListEmpty()
{
    return mListeners.isEmpty();
}

inline boolean EventManager::isListenerListFull()
{
    return mListeners.isFull();
}

inline boolean EventManager::isEventQueueEmpty( EventPriority pri )
{
    return ( pri == kHighPriority ) ? mHighPriorityQueue.isEmpty() : mLowPriorityQueue.isEmpty();
}

inline boolean EventManager::isEventQueueFull( EventPriority pri )
{
    return ( pri == kHighPriority ) ? mHighPriorityQueue.isFull() : mLowPriorityQueue.isFull();
}

inline int EventManager::getNumEventsInQueue( EventPriority pri )
{
    return ( pri == kHighPriority ) ? mHighPriorityQueue.getNumEvents() : mLowPriorityQueue.getNumEvents();
}

inline boolean EventManager::queueEvent( int eventCode, String* eventParam, EventPriority pri )
{
    if( pri == kHighPriority ) {
        mHighPriorityQueue.queueEvent( eventCode, eventParam );
    } else {
        mLowPriorityQueue.queueEvent( eventCode, eventParam );
    }
}




//*********  INLINES   EventManager::EventQueue::  ***********

inline boolean EventManager::EventQueue::isEmpty()
{
    return ( mNumEvents == 0 );
}


inline boolean EventManager::EventQueue::isFull()
{
    return ( mNumEvents == kEventQueueSize );
}


inline int EventManager::EventQueue::getNumEvents()
{
    return mNumEvents;
}



//*********  INLINES   EventManager::ListenerList::  ***********

inline boolean EventManager::ListenerList::isEmpty()
{
    return (mNumListeners == 0);
}

inline boolean EventManager::ListenerList::isFull()
{
    return (mNumListeners == kMaxListeners);
}

inline int EventManager::ListenerList::getNumEntries()
{
    return mNumListeners;
}


#endif

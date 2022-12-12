set(list 
        1-Introduction 
        2-Different-Types-Create-Threads
        3-Join_Detach_Joinable
        4-Mutex
        5-Mutx_Lock
        6-Try_Lock
        7-Timed-Mutex
        8-Recursive_Mutex
        9-Lock_Guard
        10-Unique_Lock
        11-Conditional_Variable
        12-DeadLock
        13-Synchronisation
        14-StdLock
        15-Promise_Future
        16-Async
        17-Produer_Consumer
        18-Synchronisation
    )

foreach(loop IN LISTS list)
    add_executable(${loop} ${loop}.cpp)
    target_link_libraries( ${loop} pthread )
endforeach()
//Nested into the if statement that check if a priority needs donated
struct thread *holder = lock->holder;
int i = 0;

//This will iterate all the way down to 10 threads
while (holder->waitingThread != NULL || i <= 10){ //if the lock holder is waiting for another lock

    //do donation - maybe this needs chanaged, probably because then will reset its priority in release
    holder->priority = curr->priroty;

    holder = get_thread_from_tid(lock->holder->waitingThread); //get the next thread
    i++;
}


//==============================================================================

//get_thread_from_tid in thread.c
struct thread *get_thread_from_tid(tid_t tidder)
{
    //go through allelem list
    struct list_elem *e;

    for (e = list_begin(&all_list); e != list_end(&all_list); e = list_next(e)){
        struct thread *t = list_entry(e, struct thread, allelem);
        if(t->tid == tidder){
            return t;
        }
    }
    return NULL;
}
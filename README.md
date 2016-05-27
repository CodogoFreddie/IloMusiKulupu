# FredLib
## Header only toolkit to do little things quickly, smally and well

This repo is filled with things I've found myself needing in a lot of projects.
It's not currently meant to be automaticaly included, as there are many files to do differnt things across the entirety of a project, though this may change in the future.
I suspect that only I will ever use this :L

## Things I'd like to do:
+ A nice logging system (but look for existing alternatives first)
+ Re-do `RandomInterface`, as it's way too verbose, and `good rand` is never used
    + Plan all the random functions you want before you start writing
    + Including a system for calcuating binary posibilitys using mulitup dice rolls in a single call (eg. 4d20, or the multi-step issue from my dissertation )
    + Make it so there's a static version of each function to be called for non-thread important things, and member methods for determenistic things
+ A system for running generic jobs in parrallel (formic engine)
+ Let the functions added to `DeferredFunctionQueue` be tagged with a sortable ID, that means function calls can be added in an arbitrary order (for Discrete Event simulation ETC)

### Place to Jot random Ideas:
+ `People` interact with `Establishments` which are contained by `Premesis`. So if you want to buy something you have to go to the shop's premesis, and interact with the establishment; the establishment's state is controled by the actions of the establishment's `Owner` and `Employees`. This creates a chanel for People to interact for Jobs,Buying,Leasure.
+ The city simulation could probably be written as a discrete event simulation:
    + Calculate the next thing an agent will do, and the time stamp of the point at which they'll do it
    + Add them to a queue, ordered by when their event executes.
    + If a player interacts with the agent, you can simply recalcuate their next event, and add them to the queue at a new position.
+ Have a look at this when you've got a free day: [http://www.memrise.com/course/39856/toki-pona-complete/](http://www.memrise.com/course/39856/toki-pona-complete/)

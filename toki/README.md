# toki pona

_notes, data, and practice about the computerisation of toki pona_

## Prolog:
Prolog was originally desiged for use with natural language processing, and logical deduction. 
This is basically exactly what you'd want for a speech-based toki pona computer interface, we just need to make sure that all valid input query scentences can be parsd into queries
Prolog is somewhat limited, as it deals better with constant universal truth, which makes it kinda difficult to have tempoary facts or facts that are only tru for ceartain people.
This could probably be patched into Prolog using specially constructed predicates; or, as we'll mostly be dealing with quite simple logical resolution (shallow trees of inference), we could re-implement a Prolog like system in-game that deals better with these extensions.

## notes:
+ With word concatinaion the next word describes the sum of all previous words


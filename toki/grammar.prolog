
li(X, Y) :- noun(X), noun(Y).
li(X, Y) :- noun(X), adjective(Y).

noun([X, Y]) :- noun(X), noun(Y).
noun([X, Y]) :- noun(X), adjective(Y).

noun(mi).
noun(kalo).
adjective(lili).

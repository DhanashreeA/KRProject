:-sorts
objectid.

:-objects
box :: objectid.

:-variables
B  :: objectid.

:-constants

holding,
putting,
opened,
closed,
throwing :: inertialFluent;

holding_box,
putting_box,
throwing_box,
opening_box,
closing_box :: inertialFluent;

hold(objectid),
put(objectid),
take(objectid),
open(objectid),
close(objectid),
throw(objectid)   :: exogenousAction.

hold(B) causes holding.
hold(box) causes holding_box.
nonexecutable hold(B) if holding.
caused -holding_box if -holding.

put(B) causes putting.
put(box) causes putting_box.
nonexecutable put(B) if putting.
nonexecutable put(B) if -holding.
caused -putting_box if -putting.

take(B) causes holding.
take(box) causes holding_box.
nonexecutable take(B) if holding.

open(B) causes opened.
open(box) causes opening_box.
nonexecutable open(B) if opened.
nonexecutable open(B) if -holding.
caused -opening_box if -opened.

close(B) causes closed.
close(box) causes closing_box.
nonexecutable close(B) if closed.
nonexecutable close(B) if -opened.
caused -closing_box if -closed.

throw(B) causes throwing.
throw(box) causes throwing_box.
throw(B) causes -holding.
nonexecutable throw(B) if -holding.
caused -throwing_box if -throwing.

nonexecutable hold(B) if close(B).
nonexecutable hold(B) if open(B).
nonexecutable hold(B) if throw(B).
nonexecutable hold(B) if put(B).
nonexecutable hold(B) if take(B).

nonexecutable close(B) if open(B).
nonexecutable close(B) if throw(B).
nonexecutable close(B) if put(B).
nonexecutable close(B) if take(B).

nonexecutable open(B) if throw(B).
nonexecutable open(B) if put(B).
nonexecutable open(B) if take(B).

nonexecutable throw(B) if put(B).
nonexecutable throw(B) if take(B).

nonexecutable put(B) if take(B).

:- query
label :: 0;
maxstep :: 1..5;
0: -holding&-putting&-closed&-throwing&-opened;
maxstep: closing_box.

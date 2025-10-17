% LOAD - this section has to do with the game loading process
:-use_module(library(lists)). 
  :-dynamic ball/2. 
  :-dynamic height/1. 
  :-dynamic width/1.
  :-dynamic the_end/1.
  :-dynamic win/1.

% loads game setting the file "mapa.pl" as default map 
start:-
    new_world('mapa'),
    draw_world.

%  restarts the game
restart:-
    reconsult('pacman'),
    start.

% Game Over event  
the_end(Ghost):- write('GAME OVER'), nl, write(Ghost), write(' got ya!').

% Win event
win:- nl, write('U WIN!'),nl.

% GAME - this section has to do with the main elements of the game
% Creates a new world (map) from a selected file
new_world :- 
    write('Indique path de novo Mundo:'), 
    read(Whatever),
    new_world(Whatever).

new_world(Whatever):-
    consult(Whatever),
    grid([P|G]), 
    length([P|G],H), 
    retract(height(_)), 
    assert(height(H)), 
    length(P,W), 
    retract(width(_)), 
    assert(width(W)), 
    create_balls. 

% these are just pre-defined values to width and height of map
% (they will never be used, however they are necessary to the well behaviour of the program)
width(0).
height(0).

% Gets an element by its coordinates   
element(X,Y,Whatever):- 
    grid(G), 
    nth1(Y,G,Line), 
    nth1(X,Line,Whatever). 

% This auxiliary procedure asserts all the ball coordinates in the beggining of the game 
create_balls :- 
    element(X,Y,0), 
    assert(ball(X,Y)), 
    fail. 
create_balls. 

% INTERFACE - this section has to do with drawing the game elements
% Draws a new world (Main Interface procedure)
draw_world :- 
    height(Lim), 
    draw_lines(1,Lim). 

% Auxiliary procedure which draws all lines using draw_line(Y)   
draw_lines(Y,Lim) :- 
    Y > Lim,!. 
draw_lines(Y,Lim) :- 
    draw_line(Y), 
    nl, 
    NY is Y+1, 
    draw_lines(NY,Lim). 

% Draws a single line 
draw_line(Y) :- 
    width(Lim), 
    draw_a_line(1,Y,Lim). 

% Draws all chars of a selected line
draw_a_line(X,_,Lim) :- 
    X > Lim. 
draw_a_line(X,Y,Lim) :- 
    X =< Lim, 
    draw(X,Y), 
    NX is X + 1, 
    draw_a_line(NX,Y,Lim). 

% Draw X,Y coordinates 
draw(X,Y):- 
    ghost(X,Y,_), 
    draw_ghost. 

draw(X,Y):- 
    pacman(X,Y,Type), 
    draw_pacman(Type). 

draw(X,Y):- 
    diamond(X,Y), 
    draw_diamond. 

draw(X,Y):- 
    element(X,Y,T), 
    draw(X,Y,T). 

draw_ghost:-write('A'). 
draw_diamond:-write('V'). 
draw_pacman(normal):-write('@'). 
draw_pacman(strong):-write('*'). 
draw(X,Y,0):-ball(X,Y),write('.'). 
draw(_,_,0):-write(' '). 
draw(_,_,1):-write('#').
draw(_,_,BlackHole) :- BlackHole > 1,write('~').

% DYNAMICS - this section has to do with basic movement procedures
% Change PAC-MAN Position 

move_pacman(X,Y):-
    ghost(X,Y,_),
    pacman(_,_,normal),
    fail.

/*  retract(pacman(_,_,normal)),
assert(pacman(X,Y,normal)),
restart,
the_end(Ghost).
*/

move_pacman(X,Y):-
    blackhole(X,Y,NX,NY),  
    test_pos(NX,NY),
    retract(pacman(_,_,T)),
    assert(pacman(NX,NY,T)).

move_pacman(X,Y):-
    test_pos(X,Y),
    retract(pacman(_,_,T)),
    assert(pacman(X,Y,T)).

% Change Ghosts Position  
move_ghosts:-
    ghost(X,Y,'Red'),
    ghost(W,Z,'Black'),
    h1(X,Y,NX,NY),
    move_ghost(NX,NY,'Red'),
    h1(W,Z,NW,NZ),
    move_ghost(NW,NZ,'Black').

move_ghost(X,Y,Z):-
    blackhole(X,Y,NX,NY),
    retract(ghost(_,_,Z)),
    assert(ghost(NX,NY,Z)).

move_ghost(X,Y,Z):-
    retract(ghost(_,_,Z)),
    assert(ghost(X,Y,Z)).

% implements this game and handles WIN and GAME-OVER events
play :-
    ghost(X,Y,Ghost),
    pacman(X,Y,normal),
    restart,
    the_end(Ghost).

play :-
    findall(element(X,Y,0),ball(X,Y),L),
    L == [],
    win.

play:-
    read(S),move(S),!,move_ghosts,draw_world,play.
play:-play.

move :-
    read(INPUT),
    move(INPUT).

% sets moving directions to the Human player
move(8):-
    pacman(X,Y,_),
    NY is Y - 1,
    move_pacman(X,NY).

move(2):-
    pacman(X,Y,_),
    NY is Y + 1,
    move_pacman(X,NY).

move(4):-
    pacman(X,Y,_),
    NX is X - 1,
    move_pacman(NX,Y).

move(6):-
    pacman(X,Y,_),
    NX is X + 1,
    move_pacman(NX,Y).

% RULES - this section sets restritions and special events
% tests a position about the existance of ghosts, walls and also
test_pos(X,Y):-
    ghost(X,Y,_),
    assert(the_end).

test_pos(X,Y):-
    element(X,Y,1),
    write('invalid move - Error: Wall on the way'),
    nl,!,fail.

test_pos(X,Y):-
    retract(ball(X,Y)).

test_pos(X,Y):-
    \+element(X,Y,_),
    write('invalid move - Error: Outer Space'),
    nl,!,fail.

test_pos(X,Y):-
    \+ball(X,Y).

% handles blackhole positions 
blackhole(X,Y,NX,NY):-
    element(X,Y,Z),
    Z > 1,
    element(NX,NY,Z),
    \+ (NX == X,NY == Y),!. 

% AI - sets Artificial Inteligence

% heuristic1 - gives the "shortest" path to find pacman

h1(X,Y,NX,NY):-
    aux(X,Y,A,B),
    A == 0,
    B == 0,
    NX is X,
    NY is Y.

h1(X,Y,NX,NY):-
    aux(X,Y,A,B),
    A > 0,
    abs(A) >= abs(B),
    NX is X + 1,
    NY is Y,
    adjs((X,Y),P),
    member((NX,NY),P).

h1(X,Y,NX,NY):-
    aux(X,Y,A,B),
    A < 0,
    abs(A) >= abs(B),
    NX is X - 1,
    NY is Y,
    adjs((X,Y),P),
    member((NX,NY),P).

h1(X,Y,NX,NY):-
    aux(X,Y,A,B),
    B > 0,
    abs(B) > abs(A),
    NY is Y + 1,
    NX is X,
    adjs((X,Y),P),
    member((NX,NY),P).

h1(X,Y,NX,NY):-
    aux(X,Y,A,B),
    B < 0,
    abs(B) > abs(A),
    NY is Y - 1,
    NX is X,
    adjs((X,Y),P),
    member((NX,NY),P).

h1(X,Y,NX,NY):-
    adjs((X,Y),P),
    member((NX,NY),P).

% auxiliary predicate to obtain horizontal/vertical distance to target (pac-man)
aux(X,Y,A,B):-
    pacman(W,Z,normal),
    A is W - X,
    B is Z - Y.

% this auxiliary predicate gives free adjacent positions to X,Y coordinates
adjs(P,As) :-
    findall((X,Y),(adj(P,(X,Y)),\+ element(X,Y,1)),As).

adj((X,Y),(X,NY)) :-
    height(H),
    Y < H,
    NY is Y + 1.

adj((X,Y),(X,NY)) :-
    Y > 1,
    NY is Y - 1.

adj((X,Y),(NX,Y)) :-
    width(W),
    X < W,
    NX is X + 1.

adj((X,Y),(NX,Y)) :- 
    Y > 1,
    NX is X - 1.

distance((X,Y),(X2,Y2),D) :-
    D is abs(X - X2) + abs(Y - Y2).

% MISCELLANEOUS - this section has to do with non important stuff
% auxiliary predicate that lists creatures and its positions
creatures:-
    pacman(X,Y,Z),
    status('Pacman',X,Y,Z),
    ghost(_,_,C),
    creature_ghosts(C).

creature_ghosts(C):-
    ghost(A,B,C),
    nl,
    status('Ghost',A,B,C),
    C \= F,
    creature_ghosts(F).

status(A,X,Y,Z):-
    write(A),write(': '),write(Z),write(' X='),write(X),write(' Y='),write(Y).

dump(A,B):-
    write('A: '),write(A),nl,
    write('B: '),write(B),nl.



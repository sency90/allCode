% this is the default map for PAC-MAN
  
% don't mess with this
:-dynamic pacman/3. 
:-dynamic ghost/3. 
:-dynamic diamond/2.  

% draw the pretended map using number in each position
% See the README below for further information about it
grid([[1,1,1,3,1,1,1], 
      [1,0,0,0,0,0,1], 
      [1,0,1,1,1,0,1], 
      [2,0,0,0,0,0,2], 
      [1,0,1,0,1,0,1], 
      [1,0,0,0,0,0,1], 
      [1,1,1,3,1,1,1]]).

pacman(2,2,normal). 
ghost(6,6,'Black'). 
ghost(4,6,'Red'). 
diamond(2,6).

		/* README

X - horizontal coordinate ((X=1) left / right (X=width(lim)))

Y - vertical coordinate ((Y=1) top / bottom (Y=height(lim)))

pacman - pacman(X,Y,normal) 
         where X and Y are the starting position's coordinates and normal
	 is the starting state of the pacman (normal/super)
	 
	  e.g.: pacman(3,2,normal).
		this predicate defines the starting position to pacman at the 
		coordinates X=3 and Y=2 with the normal state

ghost(s) - ghost(X,Y,'name').
	   where X and Y are the starting position's coordinates and name identifies
	   the pretended ghosts

	    e.g.: ghost(6,5,'Valek').
		this predicate defines the starting position to a ghost at the 
		coordinates X=6 and Y=5 with the name Valek

walls - can be defined setting 1 at the wanted position

free positions - can be defined setting 0 at the wanted position

black holes - can be dinamycally defined inserting a number > 1 in the pretended
              source position and the same number in the destination position

Tip: don't mess with anything else if you don't know what u're doing

*/

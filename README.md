# Fillit
## Project objective
  Searching the optimal solution among a huge set of possibilities, in a respectable timing.  
In this particular project, it is required to find a way to assemble a given Tetriminos set altogether in the smallest possible square.
## Skills to acquire and use
•	Fundamentals of C  
•	Algorithm elaboration  
•	Team work  
•	Familiarizing with a recurring problematic in programming  
## How to run it? (works on Linux and MacOS)
•	git clone https://github.com/DaniilMD/Fillit.git «Folder name»  
•	cd «Folder name»  
•	make  
•	./fillit tetr_sets/«Set name» (for example ./fillit tetr_sets/1)  

## What does it do?
1) Fillit receives a text files that represents a set of tetriminos in a format like this:

2) Then finds the smallest possible square all tetriminos can fit in.
 
## How it works
1) First of all, Fillit creates a set of all (19) possible valid tetriminos and saves them in a 3-dimensional array «g_valids».  
> Because each tetrimino fills only 4 of the 16 available boxes, it is possible to describe the same tetrimino in multiple ways.  
Rotated tetrimino describes a different tetrimino from the original.  
No rotation is possible on a tetrimino, when it is being arranged with the others.  
2) Secondly, Fillit parses the text file given to it in the 1-st argument and saves the whole tetrimino set in a different 3-d array «g_tetrs».  
3) Then, validator checks if all parsed tetriminos are correct.  
> A tetrimino is valid if the sum of neighborings is 6 or 8 (for a square tetrimino). A neighboring is such position of ‘#’ that it has another ‘#’ next to it.
4) A minimum size of square is set depending on the amount of tetriminos.  
5) Finally, a method of recursive backtracking is applied.  
> Each time, when all possible combinations of tetrimino positions are checked and the set doesn't fit the square, it is recreated with the side size 1 bigger. The whole recursive algorithm starts again. This process repeats until «the smallest square possible» to fit the tetrimino set is found.  
  
Algo is built in the way that it corresponds the task:  
> Tetriminos are ordered by their apparition order in the file. Among all the possible candidates for the smallest square, only the one where tetriminos are placed on their most upper-left positions is accepted. Tetriminos can't overlap one another.  

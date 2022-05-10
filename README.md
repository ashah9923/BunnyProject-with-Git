# Bunny Project
This projects task was to create a list of bunny objects with the following attributes:
gender, colour, age, name, infected, and run a simulation.

## Aim of the Project
Goals that were set out to achieve:

⦁	At program initialization, 5 bunnies must be created and given random colours, age can be 0 or random between 0 and 9.
⦁	Each turn,  the bunnies age 1 year.
⦁	As long as there is a male (aged 2 or older), for each female in the list (aged 2 or older) a new bunny is created each turn. (E.G. if there was 1 adult male and 3 adult females, three new bunnies would be born each turn)
⦁	New born bunnies should be the same colour as their mother.
⦁	If a bunny becomes older than 10 years old, it dies.
⦁	If an infected bunny is born, each turn it will change one normal bunny into a infected bunny (E.G.If there are two infected bunnies two bunnies will be changed each turn and so on...)
⦁	Infected bunnies are excluded from regular breeding and do not count as adult bunnies.
⦁	Infected do not die until they reach age 50.
⦁	Each turn, The program should print a list of all the bunnies in the colony with all the details, sorted by age.
⦁	The program should also output each turns events such as:
    ⦁	Bunny Keith was born!
    ⦁	Bunny Carrol was born!
    ⦁	Infected Bunny Steve was born!
    ⦁	Bunny Susan died!
⦁	When all the bunnies have died the program terminates.
⦁	If the bunny population exceeds 1000 a food shortage must occur killing exactly half of the bunnies (randomly chosen)

## Additional feature
Additional features added included a option to randomly kill half the bunnies at any point by pressing k key

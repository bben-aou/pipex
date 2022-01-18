# pipex + Bonus
This a project of 42Cursus . . .  <br />
<br />
The aim of mandatory part of this project is to understand a bit deeper how pipes and redirections work.  <br />
The aim of The Bonus part of this project is to understand a bit deeper how  multipipes and Heredoc work.  <br />
## Information : 

- Status: finished 
- Result: 125%
- Observations: (none)

## How it should work 
> Redirecting Input and Output :

*Our Command :*


`./pipex (input file) (command 1) (command 2) (...) (output file)` <br />

*Should be like :*

`< (input file) (command 1) | (command 2) | (...) > (output file)` <br />

> Heredoc :

*Our Command :*

`./pipex here_doc (LIMITER) (command 1) (command 2) (...) (output file)` <br />

*Should be like :*

`<< (LIMITER) (command 1) | (command 2) | (...) >> (output file)`

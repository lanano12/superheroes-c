# Build Circle Superheroes tech test

Superheroes and Supervillains are always battling it out, but how do we know who wins? This repo contains a function that gives us that answer. 

Some recent battles are stored in our log files - [https://dc-battles.s3.eu-west-2.amazonaws.com/dc_battles.csv](https://dc-battles.s3.eu-west-2.amazonaws.com/dc_battles.csv)

## Task

Note: This tech test is deliberately loose. We're looking for your opinions and coding style.

Above all, Build Circle values clear, well-tested code.

1. With supporting tests, write a function that calculates the winner of some recent superhero battles, the function should return the winner of each battle. The log file can be downloaded [here](https://dc-battles.s3.eu-west-2.amazonaws.com/dc_battles.csv), your function can read a stream of the file or you can hard code the table. You only need to consider the "happy" path but there should be unit tests.

2. Using any method you like, compile this to run on an ARM processor.

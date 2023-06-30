# Build Circle Superheroes tech test

Superheroes and Supervillains are always battling it out, but how do we know who wins? This repo contains a function that gives us that answer. 

The characters and their stats are stored in a json file stored in AWS S3 - https://s3.eu-west-2.amazonaws.com/build-circle/characters.json

## Task

Note: This tech test is deliberately loose. We're looking for your opinions and coding style.

Above all, Build Circle value clear, well tested code.

1. With supporting tests, write a function that takes a hero name and a villain name as inputs and returns who would win in a battle based on these [characters](https://s3.eu-west-2.amazonaws.com/build-circle/characters.json). The character with the highest score wins. You only need to consider the "happy" path.

2. Using any method you like, compile this to run on an ARM processor.

# Rubiks Encryption Algorithm
The algorithm is a substitution cipher algorithm used to reduce the common number of occurences. This is done with the use of three rubiks cube (3x3x3) and each character is assigned a random cube which is chosen from a evenly distributed randomly generated sequence.

The key generation is done by creating a randomly generated and evenly distributed of length 100. The key performs the following 12 operations on the cube -
1. Front & front prime
2. Up & up prime
3. Back & back prime
4. Left & left prime
5. Right & right prime
6. Down & down prime

All the cubes are initialized with a default configuration. The cube looks as follows -
![Cube Default Configuration](Pictures/cubeDiagram.png?raw=true "Cube Default Configuration")

Following things can be noticed -
- The **face 0** of the cube is the center most face. The next face is the one above it and then it goes in a clockwise manner.
- The characters **'X'** after the digit **'9'** are the randomly generated characters.
- The ` character is a special character that is used for spaces. 


## How to run
1. Make sure you have at least c++11 compiler on your device.
2. Clone this repo. `git clone https://github.com/arp1561/Rubiks-Cube-Encryption`
3. Navigate to the testing folder by `cd testing/` and compile the **EncrptionTest.cpp** program with the following command.
`g++ EncryptionTest.cpp ../src/Encryption.cpp ../src/Cube.cpp ../src/Generator.cpp ../src/Converter.cpp` for **encryption**.
4. The input can be changed in the input folder. 
5. After adding an input text, run the encryption using `./a.out` 
6. The ciphertext, asciivalues, keys can all be seen in the output folder.

1. Navigate to the testing folder and run the **DecryptionTest.cpp** program with the following command.
`g++ DecryptionTest.cpp src/Encryption.cpp src/Cube.cpp src/Generator.cpp src/Converter.cpp ` for **Decryption**.

# tCppMidterm
tCppMidterm -- Midterm for C++ Fall '23

Your midterm program will be  a collaboration of lab partners. You will present your program to your classmates on the presentation date and participate in the class code review by accepting all critiques without feedback. For example, a code review committee member says, "Good animal names, but your code was unreadable." and you and your partner say, "Thank you for your feedback."

To constrain the scope to current class instruction, limit input to four animals from each of four species (16 animals).

The following programming concepts will be demonstrated:

-- Clear, Concise, and Correct Code: Program must be written in the class programming style guide.

-- File I/O: Create a file, write to a file, open a file, read from a file, close a file, delete a file, append to a file, etc.

-- Exception Handling: Standard file IO exceptions, create an exception to handle adding an animal to a habitat that does not have enough room for the new animal.

-- Functions, Classes, and Lists: You must demonstrate functions, classes, and linked list(s) as needed to implement your program design. Array use is your choice! 

-- Input - File and String Handling: Parse string data from input files. 

-- Output - Formatted Output: Output a report listing the zoo animals with their attributes and their habitats (zooPopulation.txt)

Animals are arriving from zoos around the world and you must give them names and bithdates and a nice new home (organize then into habitats). To accomplish this task, you will write a Java program that:

1) Finds the age, sex, species, color, and weight of each animal from an input text file (arrivingAnimals.txt)

2) Calculate a birthday based on input data

3) Create a name for each animal using names collected from a recent community fund raiser (animalNames.txt)

4) Create a unique ID for each animal to be used in your zoo information system. This id will start with the first two chars of the animal's species. 

5) The zoo keeper will assign a sound that the animal makes after the animal's physical and assign this sound to a field in the animal's class. 

6) Process the animals into appropriate habitats

7) Output a report (zooPopulation.txt) containing all zoo animals and their information.

Use at least five functions with the following names. These functions must be explained to the code review committee. The five functions will be named:

genBirthDay(), genUniqueAnimalID(), genAnimalName(), genZooHabitat(), getArrivalDate()

Use file i/o to parse and input the file named arrivingAnimals.txt. Use File i/o to create a report named zooPopulation.txt.  Use the data structures we've been studying to organize your zoo.

You will use functions/methods to calculate the following data elements for each animal:

Unique animal ID, animal name, birth date, color, weight, origin

You must place species in their own habitat and output that in a report similar to:

Hyena Habitat:

Hy01; Kamari; 4 years old; birth date Mar 21, 2018; tan color; female; 70 pounds; from Friguia Park, Tunisia; arrived Sept 27, 2022

Lion Habitat:

Li01; Kiara; 6 years old; birth date Sept 21, 2016; tan color; female; 305 pounds; from Zanzibar, Tanzania; arrived Sept 23, 2022

Names to get you started:

Hyena Names:

Shenzi, Banzai, Ed, Zig, Bud, Lou, Kamari, Wema, Nne, Madoa, Prince Nevarah

Lion Names:

Scar, Mufasa, Simba, Kiara, King, Drooper, Kimba, Nala, Leo, Samson, Elsa, Cecil

Bear Names:

Yogi, Smokey, Paddington, Lippy, Bungle, Baloo, Rupert, Winnie the Pooh, Snuggles, Bert

Tiger names:

Tony, Tigger, Amber, Cosimia, Cuddles, Dave, Jiba, Rajah, Rayas, Ryker

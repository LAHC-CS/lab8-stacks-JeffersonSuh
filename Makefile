SRC=src

exercise_1.out:
	@ mkdir -p bin
	g++ $(SRC)/exercise_1.cpp -o bin/exercise_1

exercise_2.out:
	@ mkdir -p bin
	g++ $(SRC)/exercise_2.cpp -o bin/exercise_2


clean:
	rm -r bin

test: exercise_1.out exercise_2.out 
	bash test.sh exercise_1 " " " "
	bash test.sh exercise_2 " " " "

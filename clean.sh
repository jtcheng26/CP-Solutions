# Script deletes all executable binaries, .out files, .exe files
# Made and tested on MacOS zsh shell

echo 'Cleaning...'

NUM_OUT=$(find Contests -type f -name '*.out' | wc -l)

find Contests -type f -name '*.out' -delete

NUM_EXE=$(find Contests -type f -name '*.exe' | wc -l)

find Contests -type f -name '*.exe' -delete

NUM_BIN=$(find Contests -type f -name '*.bin' | wc -l)

find Contests -type f -name '*.bin' -delete

NUM_EXB=$(find Contests -type f ! -name "*.*" | wc -l)

find Contests -type f ! -name "*.*" -delete # **/* to ignore git binaries

echo "Deleted .out files:      $(($NUM_OUT))"
echo "Deleted .exe files:      $(($NUM_EXE))"
echo "Deleted .bin files:      $(($NUM_BIN))"
echo "Deleted binaries:        $(($NUM_EXB))"
echo "Total deleted:           $(($NUM_OUT + $NUM_EXE + $NUM_BIN + $NUM_EXB))"
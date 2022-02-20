package main

import (
	"fmt"
	"time"
	"math/rand"
)

const (
	VOWELS = "aeiou"
	CONSONANTS = "bcdfghjklmnpqrstvwxyz"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	for i := 0; i < 3; i++ {
		fmt.Print(string(CONSONANTS[rand.Intn(len(CONSONANTS))]))
		fmt.Print(string(VOWELS[rand.Intn(len(VOWELS))]))
	}
	fmt.Println()
}

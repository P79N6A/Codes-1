package main

import (
	"fmt"
	"math/rand"
)

func add(x int, y int) int {
	return x + y
}

func swap(x, y string) (string, string) {
	return y, x
}

func main() {
	fmt.Println("Hello! World!")
	rand.Seed(751744014)
	fmt.Println(rand.Intn(10))
	fmt.Println(add(10, 20))
	a, b := swap("hello", "world")
	fmt.Println(a, b)
}

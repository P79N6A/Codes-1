package main

import (
	"fmt"
	"math/rand"
)

const (
	// 将 1 左移 100 位来创建一个非常大的数字
	// 即这个数的二进制是 1 后面跟着 100 个 0
	Big = 1 << 100
	// 再往右移 99 位，即 Small = 1 << 1，或者说 Small = 2
	Small = Big >> 99
)

func add(x int, y int) int {
	return x + y
}

func swap(x, y string) (string, string) {
	return y, x
}

func multiply(x, y int) (mx, my int) {
	mx = x * 10
	my = y * 20
	return
}

func main() {
	fmt.Println("Hello! World!")
	rand.Seed(751744014)
	fmt.Println(rand.Intn(10))
	fmt.Println(add(10, 20))
	a, b := swap("hello", "world")
	fmt.Println(a, b)
	fmt.Println(multiply(10, 10))
	for i := 0; i < 10; i++ {
		fmt.Println(i)
	}
}

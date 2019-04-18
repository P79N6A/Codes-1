package main

import (
	"fmt"
	"math/rand"
	"encoding/json"
	"github.com/go-redis/redis"
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

	x, y := 12, 88
	fmt.Printf("x = %d, p = %p\n", x, &x)
	fmt.Printf("y = %d, p = %p\n", y, &y)
	x, z := 88, 70
	fmt.Printf("x = %d, p = %p\n", x, &x)
	fmt.Printf("z = %d, p = %p\n", z, &z)

	raw := `{ "Name" : "Platypus" , "Order" : "Monotremata" , "Time" : 123 } `
	type Animal struct {
		Name  string
		Order string
	}
	var rawData = []byte(raw)
	var animal Animal
	json.Unmarshal(rawData, &animal)
	fmt.Println(animal.Order)

	r := redis.NewClient(&redis.Options{
		Addr:     "localhost:6379",
		Password: "", // no password set
		DB:       0,  // use default DB
	})
	data, _ := r.Get("test").Result()
	fmt.Println(data)
	blob := []byte(data)
	type A struct {
		Name string
		Age int8
		T int64
	}
	p := new(A)
	json.Unmarshal(blob, &p)
	fmt.Println(p)

	li := []string{"UC浏览器"}
	fmt.Println(li)
}

package main

import "fmt"
import "time"

func producer(ch_buffer chan int) {

	for i := 0; i < 10; i++ {
		time.Sleep(100 * time.Millisecond)
		fmt.Printf("[producer]: pushing %d\n", i)
		// TODO: push real value to buffer
		ch_buffer <- i
	}
	close(ch_buffer)

}

func consumer(ch_buffer chan int) {

	time.Sleep(1 * time.Second)
	for i := range ch_buffer { //TODO: get real value from buffer
		fmt.Printf("[consumer]: %d\n", i)
		time.Sleep(50 * time.Millisecond)
	}

}

func main() {

	// TODO: make a bounded buffer
	ch_buffer := make(chan int, 5)

	go consumer(ch_buffer)
	go producer(ch_buffer)

	select {}
}

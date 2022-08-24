package main

import (
	"container/list"
	"fmt"
)

var s []rune
var adj [][]int

func ai(a rune) int {
	return int(a - 'A')
}

func getDists() [][]int {
	dist := make([][]int, 26)
	for i := 0; i < 26; i++ {
		dist[i] = make([]int, 26)
	}

	for l := 0; l < 26; l++ {
		for j := 0; j < 26; j++ {
			dist[l][j] = -1
		}
		q := list.New()
		q.PushBack(l)
		dist[l][l] = 0

		for top := q.Front(); top != nil; top = top.Next() {
			node := top.Value.(int)
			for _, child := range adj[node] {
				if dist[l][child] == -1 {
					dist[l][child] = dist[l][node] + 1
					q.PushBack(child)
				}
			}
		}
	}

	return dist
}

func printDists(d [][]int) {
	for i := 0; i < 26; i++ {
		for j := 0; j < 26; j++ {
			fmt.Printf("%d ", d[i][j])
		}
		fmt.Println()
	}
}

func solve() int64 {
	d := getDists()
	var ans int64 = 100000000
	for l := 0; l < 26; l++ {
		var cost int64 = 0
		good := true
		for _, c := range s {
			letter := ai(c)
			if d[letter][l] == -1 {
				good = false
			} else {
				cost += int64(d[letter][l])
			}
		}
		if good {
			if cost < ans {
				ans = cost
			}
		}
	}

	if ans == 100000000 {
		return -1
	}

	return ans
}

func main() {
	var t int
	fmt.Scanln(&t)
	for c := 1; c <= t; c++ {
		var temp string
		fmt.Scanln(&temp)
		s = []rune(temp)
		var k int
		var ab string
		fmt.Scanln(&k)
		adj = make([][]int, 26)
		for j := 0; j < 26; j++ {
			adj[j] = make([]int, 0)
		}
		for i := 0; i < k; i++ {
			fmt.Scanln(&ab)
			l := ai([]rune(ab)[0])
			r := ai([]rune(ab)[1])
			adj[l] = append(adj[l], r)
		}
		fmt.Printf("Case #%d: %d\n", c, solve())
	}
}

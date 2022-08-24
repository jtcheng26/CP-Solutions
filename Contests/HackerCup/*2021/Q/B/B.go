package main

import (
	"fmt"
)

type Count struct {
	X int
	O int
}

type Data struct {
	Row []Count
	Col []Count
}

var n int
var a [][]rune

func getData() *Data {
	d := Data{
		Row: make([]Count, n),
		Col: make([]Count, n),
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if a[i][j] == 'X' {
				d.Row[i].X++
			}
			if a[i][j] == 'O' {
				d.Row[i].O++
			}

			if a[j][i] == 'X' {
				d.Col[i].X++
			}
			if a[j][i] == 'O' {
				d.Col[i].O++
			}
		}
	}

	return &d
}

func solve() (int, int) {
	d := getData()
	best := 100
	cnt := 0
	for i := 0; i < n; i++ {
		if d.Row[i].O == 0 {
			if n-d.Row[i].X == best {
				cnt++
			} else if n-d.Row[i].X < best {
				best = n - d.Row[i].X
				cnt = 1
			}
		}

		if d.Col[i].O == 0 {
			if n-d.Col[i].X == best {
				cnt++
			} else if n-d.Col[i].X < best {
				best = n - d.Col[i].X
				cnt = 1
			}
		}
	}

	if best == 100 {
		return -1, -1
	}

	if best == 1 {
		sub := 0
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				if a[i][j] == '.' && d.Row[i].X == n-1 && d.Col[j].X == n-1 {
					sub++
				}
			}
		}
		return 1, cnt - sub
	}
	return best, cnt
}

func main() {
	var t int
	fmt.Scanln(&t)

	for c := 0; c < t; c++ {
		fmt.Scanln(&n)
		a = make([][]rune, n)
		var temp string
		for i := 0; i < n; i++ {
			fmt.Scanln(&temp)
			a[i] = make([]rune, n)
			for j, char := range temp {
				a[i][j] = char
			}
		}
		best, cnt := solve()
		if best == -1 {
			fmt.Printf("Case #%d: Impossible\n", c+1)
		} else {
			fmt.Printf("Case #%d: %d %d\n", c+1, best, cnt)
		}
	}
}

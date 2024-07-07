package main

func sqtX(x int) int {
	if x == 0 || x == 1 {
		return x
	}

	return sqtHelper(x, 0, x)
}

func sqtHelper(x, low, high int) int {
	if low > high {
		return high
	}

	mid := low + (high-low)/2
	if mid*mid == x {
		return mid
	}

	if mid*mid < x {
		return sqtHelper(x, mid+1, high)
	}

	return sqtHelper(x, low, mid-1)
}

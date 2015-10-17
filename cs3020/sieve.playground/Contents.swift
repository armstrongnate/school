//: Playground - noun: a place where people can play

import UIKit

func sieve(n: Int) -> [Bool] {
    var a = [Bool](count: n, repeatedValue: true)
    a[0] = false
    a[1] = false
    for i in 2..<n {
        if a[i] {
            for var j=i*2; j<n; j+=i {
                a[j] = false
            }
        }
    }
    return a
}

let s = sieve(32)

func isPrime(n: Int) -> Bool {
    return s[n]
}

let primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]

func test() -> Int? {
    for i in 0...31 {
        if contains(primes, i) {
            if !isPrime(i) { return i }
        }
        else {
            if isPrime(i) { return i }
        }
    }
    return nil
}

let awesome = test()
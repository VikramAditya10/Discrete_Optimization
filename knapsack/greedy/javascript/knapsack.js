const max = (a, b) => {
  return (a > b) ? a : b
}
const knapSack = (n, W, values, weights) => {
  if (n === 0 || W === 0) {
    return 0
  }
  if (weights[n - 1] > W) {
    knapSack(n - 1, W, values, weights)
  } else {
    return max(values[n - 1] + knapSack(n - 1, W - weights[n - 1], values, weights), knapSack(n - 1, W, values, weights))
  }
}
console.time()
const n = 4
const W = 11
const values = [8, 10, 15, 4]
const weights = [4, 5, 8, 3]
console.log('The value is')
console.log(knapSack(n, W, values, weights))
console.timeEnd()

const heapsort = (arr, length, i) => {
    let largest = i
    const left = i * 2 + 1
    const right = left + 1
  
    if (left < length && arr[left] > arr[largest]) {
      largest = left
    }
  
    if (right < length && arr[right] > arr[largest]) {
      largest = right
    }
  
    if (largest !== i) {
      [arr[i], arr[largest]] = [arr[largest], arr[i]]
      heapsort(arr, length, largest)
    }
  
    return arr
  }
  
  const heapSort = arr => {
    const length = arr.length
    let i = Math.floor(length / 2 - 1)
    let k = length - 1
  
    while (i >= 0) {
      heapsort(arr, length, i)
      i--
    }
  
    while (k >= 0) {
      [arr[0], arr[k]] = [arr[k], arr[0]]
      heapsort(arr, k, 0)
      k--
    }
  
    return arr
  }
  
  const arr = [4, 6, 3, 2, 9];
  sortedArr = heapSort(arr);
  
  console.log("Sorted array is \n", sortedArr)
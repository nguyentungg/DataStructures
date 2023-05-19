# Write a function called calculateAverage which accepts an array of numbers. 
# The function should return the average or mean of all number in the array. If the array is empty return 0.


def calculateAverage(numbers):
    if not numbers:  # Check if the array is empty
        return 0

    total = sum(numbers)
    average = total / len(numbers)
    return average

numbers = [1, 2, 3, 4, 5]
average = CAV(numbers)
print(average)  # Output: 3.0

empty_array = []
average = CAV(empty_array)
print(average)  # Output: 0
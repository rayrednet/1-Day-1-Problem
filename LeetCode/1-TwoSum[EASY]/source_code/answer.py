def two_sum(nums, target):
    hash_map = {}

    for i, num in enumerate(nums):
        number_to_find = target - num

        if number_to_find in hash_map:
            return [hash_map[number_to_find], i]

        hash_map[num] = i

    return []

def main():
    input_str = input()

    # Parse the input
    nums_start = input_str.find('[')
    nums_end = input_str.find(']')
    nums_str = input_str[nums_start + 1:nums_end]

    nums = list(map(int, nums_str.split(',')))

    target_pos = input_str.find("target = ")
    target = int(input_str[target_pos + 9:])

    result = two_sum(nums, target)

    if result:
        print(f"[{result[0]},{result[1]}]")
    else:
        print("No solution found!")

if __name__ == "__main__":
    main()

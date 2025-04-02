input_string = str(input())


def segment_string_list(input_string):
    result = []

    if not input_string:
        return result

    current_group = ""
    current_group += input_string[0]

    for i in range(1, len(input_string)):
        if input_string[i] == input_string[i - 1]:
            current_group += input_string[i]
        else:
            result.append(current_group)
            current_group = input_string[i]

    result.append(current_group)

    return result


print(segment_string_list(input_string))

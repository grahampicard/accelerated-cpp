def parse(string, sentence, stack):
  repetitions = ""
  i = 0
  string_length = len(string)

  # let's iterate each letter and add any non-bracketed
  # letter to sentence
  while i < string_length:
    current_letter = string[i]

    # first write to the string if it's not braketed
    if current_letter.isalpha():
      sentence.append(current_letter)

    # in the case of a number, append it to the repetitions
    # to convert
    if current_letter.isnumeric():
      repetitions += current_letter

    # if it's bracketed, break off the remainder and append 
    # list with the new values
    if current_letter == "[":
      j = i + 1
      brackets = 1
      pattern = ""

      # start another iterator for the pattern
      while j < string_length:
        pattern_string = string[j]
      
        # Now, let's check if there are any outstanding brackets
        # if there aren't, we'll move on to the next letter
        # we need to detect the end of the pattern. if we 
        # encounter "]" without encountering another bracket
        # we can consider the pattern closed and push back
        # the remainder
        if pattern_string == "[":
          brackets += 1
        elif pattern_string == "]":
          brackets -= 1
          if brackets == 0:
            remainder = string[j + 1:]
            stack.append(remainder)
            for _ in range(int(repetitions)):
              stack.append(pattern)
            return None
        else:
          pass

        j += 1
        pattern = pattern + pattern_string
    else:
      i += 1
  return None
      

def main():
  myInput = "g2[3[r]a]h10[a]m"
  sentence = []
  stack = []
  stack.append(myInput)

  while len(stack) > 0:
    current_string = stack.pop()
    parse(current_string, sentence, stack)

  result = ''.join(sentence)  
  print(result)


if __name__ == "__main__":
  main()
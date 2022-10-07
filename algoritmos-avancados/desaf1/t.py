def performReversal(sequence, start_index, end_index):
    prefix = sequence[:start_index]
    print("prefix ")
    print(prefix)
    reversed_subsequence = sequence[start_index:end_index][::-1]
    print("subseq ")
    print(reversed_subsequence)
    suffix = sequence[end_index:]
    print("suffix ")
    print(suffix)
    raise Error
    return prefix + reversed_subsequence + suffix

def findBreakpoints(sequence, target_sequence):
    breakpoints = []
    for index in range(len(sequence)-1):
        current_element = sequence[index]
        adjacent_element = sequence[index+1]
        if abs(target_sequence.index(current_element) - target_sequence.index(adjacent_element)) != 1:
            breakpoints.append(index+1)
    return breakpoints

def findMinimumBreakpointReversals(sequences, target_sequence):
    reversals = []
    for sequence in sequences:
        breakpoints = findBreakpoints(sequence, target_sequence)
        for start_index_i in range(len(breakpoints)-1):
            for end_index_i in range(start_index_i+1, len(breakpoints)):
                reversals.append(performReversal(sequence, breakpoints[start_index_i], breakpoints[end_index_i]))
    min_bp = len(target_sequence)
    minimum_reversals = []
    for reversal in reversals:
        num_breakpoints = len(findBreakpoints(reversal, target_sequence))
        if num_breakpoints < min_bp:
            min_bp = num_breakpoints
            minimum_reversals = [reversal]
        elif num_breakpoints == min_bp:
            minimum_reversals.append(reversal)
    return minimum_reversals

def getReversalDistance(sequence, target_sequence):
    sequence = ["-"] + sequence + ["+"]
    target_sequence = ["-"] + target_sequence + ["+"]
    reversals = 0
    current_sequences = [sequence]
    while target_sequence not in current_sequences:
        current_sequences = findMinimumBreakpointReversals(current_sequences, target_sequence)
        reversals += 1
    return reversals

if __name__ == "__main__":

    sequence = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    target_sequence = [3, 1, 5, 2, 7, 4, 9, 6, 10, 8]
    
    print(getReversalDistance(sequence, target_sequence))
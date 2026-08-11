class TrieNode:
    def __init__(self):
        self.children = {}
        self.index = -1
        self.length = float('inf')

class Solution:
    def stringIndices(self, wordsContainer, wordsQuery):
        # Build Trie
        root = TrieNode()
        global_index = 0
        global_len = len(wordsContainer[0])

        for i, word in enumerate(wordsContainer):
            n = len(word)
            if n < global_len:
                global_len = n
                global_index = i

            node = root
            for ch in reversed(word):
                if ch not in node.children:
                    node.children[ch] = TrieNode()
                node = node.children[ch]
                if n < node.length:
                    node.length = n
                    node.index = i

        root.index = global_index
        root.length = global_len

        # Search queries
        ans = []
        for query in wordsQuery:
            node = root
            best_index = root.index
            for ch in reversed(query):
                if ch not in node.children:
                    break
                node = node.children[ch]
                best_index = node.index
            ans.append(best_index)

        return ans

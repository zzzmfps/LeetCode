# 24ms, 93.05%; 11.8MB, 5.36%
class Codec:
    def __init__(self):
        self.url2tiny = {}
        self.tiny2url = []
        self.tiny_idx = -1

    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.
        
        :type longUrl: str
        :rtype: str
        """
        self.tiny_idx += 1
        self.url2tiny[longUrl] = self.tiny_idx
        self.tiny2url.append(longUrl)
        return 'http://tinyurl.com/' + str(self.tiny_idx)

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        
        :type shortUrl: str
        :rtype: str
        """
        return self.tiny2url[int(shortUrl.split('/')[-1])]

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))

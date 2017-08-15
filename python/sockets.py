from urllib import parse
from urllib import request

auth = request.HTTPBasicAuthHandler()
password = "given by Dave in class"
auth.add_password("Twitter API", "http://twitter.com", "pythonclass", password)
opener = request.build_opener(auth)

fields = {'status': "Yourname is alive!"}   # Fill in your name here
params = parse.urlencode(fields)
request = request.Request("http://twitter.com/statuses/update.json", params)
u = opener.open(request)
resp = u.read()
print(resp)

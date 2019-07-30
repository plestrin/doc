import sys
import hashlib

if len(sys.argv) != 3:
	sys.stderr.write('[-] usage : ' + sys.argv[0] + ' password engine_id\n')
	exit(-1)

pwd = sys.argv[1]
engine_id = sys.argv[2].decode('hex')

pwd_len = len(pwd)
if not pwd_len:
	sys.stderr.write('[-] empty password\n')
	exit(-1)

md5_alg = hashlib.md5()
sha_alg = hashlib.sha1()

count = 0
while count + pwd_len <= 0x100000:
	md5_alg.update(pwd)
	sha_alg.update(pwd)
	count += pwd_len

if count != 0x100000:
	md5_alg.update(pwd[:0x100000 - count])
	sha_alg.update(pwd[:0x100000 - count])

md5_ku = md5_alg.digest()
sha_ku = sha_alg.digest()

md5_alg = hashlib.md5()
sha_alg = hashlib.sha1()

md5_alg.update(md5_ku + engine_id + md5_ku)
sha_alg.update(sha_ku + engine_id + sha_ku)

sys.stdout.write('MD5 Kul : ' + md5_alg.digest().encode('hex') + '\n')
sys.stdout.write('SHA Kul : ' + sha_alg.digest().encode('hex') + '\n')

"""
Reading Larges Files
- Interaction Map: Process / OS / Hardware
- When I open a file does the language api's load everything to memory?
- How data is transfer from disk to ram?
- When the os has writing data to disk?
- ...
"""

# Generate Data:dd if=/dev/urandom of=random_data.bin bs=1M count=100

```
import psutil
process = psutil.Process()
from random import choice

BYTES_IN_MEGA=0.000001
print(process.memory_info().rss * BYTES_IN_MEGA )  # in bytes 

data = []

with open('random_data.bin', 'br') as f_out:
    # f_out.
    # print(dir(f_out))
    
    chunk_size =  1024
    f_out.read(1024)

    while True:
        read = f_out.read(chunk_size)
        data.append(read)
        # print(process.memory_info().rss * BYTES_IN_MEGA)  # in bytes 
        if not read:
            break

    print(f_out)
    print("Datos")
    print(process.memory_info().rss * BYTES_IN_MEGA)  # in bytes 

``

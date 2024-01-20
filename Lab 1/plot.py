import matplotlib.pyplot as plt
import pandas

df2 = pandas.read_csv("data.csv", names=["N", "runs", "sizeXruns", "throughput"])

N = df2["N"]
throughput = df2["throughput"]

plt.plot(N, throughput, marker='o')
plt.xscale('log', base=2)  # Use log scale for better visualization
plt.yscale('log')
plt.title('Throughput vs N for Vector Triad Benchmark')
plt.xlabel('N')
plt.ylabel('Throughput (Bytes/Second)')
plt.grid(True)
plt.show()
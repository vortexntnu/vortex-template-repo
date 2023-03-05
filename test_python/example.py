import numpy as np
import matplotlib.pyplot as plt

# Define the x range for the plot
x = np.linspace(-10, 10, 1000)

# Generate random polynomial coefficients
coefficients = np.random.randn(5)
# Compute the y values for the polynomial
y = np.polyval(coefficients, x)

# Plot the polynomial
plt.plot(x, y)
plt.xlabel("x")
plt.ylabel("y")
plt.title("Random Polynomial")
plt.show()

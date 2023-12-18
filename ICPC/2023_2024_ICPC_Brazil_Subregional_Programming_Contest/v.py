import matplotlib.pyplot as plt
from scipy.spatial import Voronoi, voronoi_plot_2d
import numpy as np

# Puntos para el diagrama de Voronoi
points_voronoi = np.array([[0, 0], [1, 3]])

# Puntos para limitar el diagrama
limit_points = np.array([[1, -1], [-1, 3], [1, 3], [-1, -1]])

# Crear el diagrama de Voronoi
vor = Voronoi(points_voronoi)

# Configuración de la visualización
fig, ax = plt.subplots()
voronoi_plot_2d(vor, ax=ax, show_vertices=False, line_colors='orange')

# Limitar el área de visualización con los puntos límite
ax.set_xlim([limit_points[:,0].min()-1, limit_points[:,0].max()+1])
ax.set_ylim([limit_points[:,1].min()-1, limit_points[:,1].max()+1])

# Mostrar el diagrama
plt.show()

# x = [1, -1, 1, -1, 1, 1, 0, -1, -1, 0]
# y = [-1, 3, 3, -1, -1, 1.333333, 1.666667, 1.333333, -1, 0]


# plt.scatter(x, y)
# plt.show()
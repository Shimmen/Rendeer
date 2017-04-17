#include "Geometry.h"

#include <math.h>

#include "Logger.h"

/*static*/ std::unique_ptr<Geometry>
Geometry::Sphere(int sectors, int rings, float radius, bool genNormals, bool genTangents, bool genTexCoords)
{
	if (genTangents)
	{
		Logger::Log("Error: tried to generate a sphere with tangents, which is not implemented! Ignoring instruction.");

		if (!(genNormals && genTexCoords))
		{
			Logger::Log("Error: tried to generate a sphere with tangents but without tex-coords and normals, which is not possible!");
			return nullptr;
		}
	}

	std::unique_ptr<Geometry> sphere{ new Geometry() };

	sphere->positions.resize(rings * sectors * 3);
	if (genNormals) sphere->normals.resize(rings * sectors * 3);
	if (genTangents) sphere->tangents.resize(rings * sectors * 3);
	if (genTexCoords) sphere->texCoords.resize(rings * sectors * 2);

	auto p = sphere->positions.begin();
	auto n = sphere->normals.begin();
	auto t = sphere->tangents.begin();
	auto tex = sphere->texCoords.begin();

	float const R = 1.0f / (float)(rings-1);
	float const S = 1.0f / (float)(sectors-1);

	for(int r = 0; r < rings; r++)
	{
		for(int s = 0; s < sectors; s++)
		{
			const float y = sinf( -M_PI_2 + M_PI * r * R );
			const float x = cosf(2*M_PI * s * S) * sin( M_PI * r * R );
			const float z = sinf(2*M_PI * s * S) * sin( M_PI * r * R );

			*p++ = x * radius;
			*p++ = y * radius;
			*p++ = z * radius;

			if (genNormals)
			{
				*n++ = x;
				*n++ = y;
				*n++ = z;
			}

			if (genTangents)
			{
				// TODO: Implement!
				*t++ = 0.0f;
				*t++ = 0.0f;
				*t++ = 0.0f;
			}

			if (genTexCoords)
			{
				*tex++ = s * S;
				*tex++ = r * R;
			}
		}
	}

	sphere->indices.resize(rings * sectors * 6); // resize for triangles
	std::vector<unsigned int>::iterator i = sphere->indices.begin();
	for(int r = 0; r < rings - 1; ++r)
	{
		for(int s = 0; s < sectors - 1; ++s)
		{
			const int i0 = r * sectors + s;
			const int i1 = r * sectors + (s + 1);
			const int i2 = (r + 1) * sectors + (s + 1);
			const int i3 = (r + 1) * sectors + s;

			// Triangles
			*i++ = i2;
			*i++ = i1;
			*i++ = i0;

			*i++ = i3;
			*i++ = i2;
			*i++ = i0;


			// Quads
			//*i++ = i0;
			//*i++ = i1;
			//*i++ = i2;
			//*i++ = i3;
		}
	}

	return sphere;
}

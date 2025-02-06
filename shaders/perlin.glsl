
// From https://www.shadertoy.com/view/slB3z3


uint murmur_hash(uint x, uint seed) {
    const uint m = 0x5bd1e995U;
    uint murmur_hash = seed;
    // process input
    uint k = x;
    k *= m;
    k ^= k >> 24;
    k *= m;
    murmur_hash *= m;
    murmur_hash ^= k;
    // some final mixing
    murmur_hash ^= murmur_hash >> 13;
    murmur_hash *= m;
    murmur_hash ^= murmur_hash >> 15;
    return murmur_hash;
}

// implementation of Murmurmurmur_hash (https://sites.google.com/site/murmurmurmur_hash/) for a  
// 3-dimensional unsigned integer input vector.

uint murmur_hash(uvec3 x, uint seed){
    const uint m = 0x5bd1e995U;
    uint murmur_hash = seed;
    // process first vector element
    uint k = x.x; 
    k *= m;
    k ^= k >> 24;
    k *= m;
    murmur_hash *= m;
    murmur_hash ^= k;
    // process second vector element
    k = x.y; 
    k *= m;
    k ^= k >> 24;
    k *= m;
    murmur_hash *= m;
    murmur_hash ^= k;
    // process third vector element
    k = x.z; 
    k *= m;
    k ^= k >> 24;
    k *= m;
    murmur_hash *= m;
    murmur_hash ^= k;
	// some final mixing
    murmur_hash ^= murmur_hash >> 13;
    murmur_hash *= m;
    murmur_hash ^= murmur_hash >> 15;
    return murmur_hash;
}


vec3 perlin_gradientDirection(uint murmur_hash) {
    switch (int(murmur_hash) & 15) { // look at the last four bits to pick a gradient direction
    case 0:
        return vec3(1, 1, 0);
    case 1:
        return vec3(-1, 1, 0);
    case 2:
        return vec3(1, -1, 0);
    case 3:
        return vec3(-1, -1, 0);
    case 4:
        return vec3(1, 0, 1);
    case 5:
        return vec3(-1, 0, 1);
    case 6:
        return vec3(1, 0, -1);
    case 7:
        return vec3(-1, 0, -1);
    case 8:
        return vec3(0, 1, 1);
    case 9:
        return vec3(0, -1, 1);
    case 10:
        return vec3(0, 1, -1);
    case 11:
        return vec3(0, -1, -1);
    case 12:
        return vec3(1, 1, 0);
    case 13:
        return vec3(-1, 1, 0);
    case 14:
        return vec3(0, -1, 1);
    case 15:
        return vec3(0, -1, -1);
    }
}

float trilinear_interp(float value1, float value2, float value3, float value4, float value5, float value6, float value7, float value8, vec3 t) {
    return mix(
        mix(mix(value1, value2, t.x), mix(value3, value4, t.x), t.y),
        mix(mix(value5, value6, t.x), mix(value7, value8, t.x), t.y),
        t.z
    );
}

vec3 perlin_fade(vec3 t) {
    // 6t^5 - 15t^4 + 10t^3
	return t * t * t * (t * (t * 6.0 - 15.0) + 10.0);
}

// return value is in range [-1,1]
// position is in [0,1] (it loops outside that region, I think)
float perlinNoise(vec3 position, uint seed) {
    vec3 floorPosition = floor(position);
    vec3 fractPosition = position - floorPosition;
    uvec3 cellCoordinates = uvec3(floorPosition);
    float value1 = dot(perlin_gradientDirection(murmur_hash(cellCoordinates, seed)), fractPosition);
    float value2 = dot(perlin_gradientDirection(murmur_hash((cellCoordinates + uvec3(1, 0, 0)), seed)), fractPosition - vec3(1, 0, 0));
    float value3 = dot(perlin_gradientDirection(murmur_hash((cellCoordinates + uvec3(0, 1, 0)), seed)), fractPosition - vec3(0, 1, 0));
    float value4 = dot(perlin_gradientDirection(murmur_hash((cellCoordinates + uvec3(1, 1, 0)), seed)), fractPosition - vec3(1, 1, 0));
    float value5 = dot(perlin_gradientDirection(murmur_hash((cellCoordinates + uvec3(0, 0, 1)), seed)), fractPosition - vec3(0, 0, 1));
    float value6 = dot(perlin_gradientDirection(murmur_hash((cellCoordinates + uvec3(1, 0, 1)), seed)), fractPosition - vec3(1, 0, 1));
    float value7 = dot(perlin_gradientDirection(murmur_hash((cellCoordinates + uvec3(0, 1, 1)), seed)), fractPosition - vec3(0, 1, 1));
    float value8 = dot(perlin_gradientDirection(murmur_hash((cellCoordinates + uvec3(1, 1, 1)), seed)), fractPosition - vec3(1, 1, 1));
    return trilinear_interp(value1, value2, value3, value4, value5, value6, value7, value8, perlin_fade(fractPosition));
}

// return value is in range [-1,1]
// position is in [0,1] (it loops outside that region, I think)
// octaveCount is how many overlapping layers we do
// frequency is what we multiply with position for the base octave
// lacunarity is what we multiply the frequency with for each octave
// persistence is the cumulative gain for each successive octave
float perlinNoise(vec3 position, uint seed, int octaveCount, float persistence=0.5, float lacunarity=2.0) {
    float value = 0.0;
    float amplitude = 1.0;
    float currentFrequency = 1.;
    uint currentSeed = seed;
    for (int i = 0; i < octaveCount; i++) {
        currentSeed = murmur_hash(currentSeed, 0x0U); // create a new seed for each octave
        value += perlinNoise(position * currentFrequency, currentSeed) * amplitude;
        amplitude *= persistence;
        currentFrequency *= lacunarity;
    }
    return value;
}
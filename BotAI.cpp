if (neuronsV.size() >= 8)
	{
		auto count = neuronsV.size() - neuronsV.size() % 8;

		__m256* vs = static_cast<__m256*>(alloca(count * sizeof(float) * 3));
		__m256* ws = vs + count / 8;
		__m256* ins = ws + count / 8;

		for (int i = 0; i < count / 8; ++i)
		{
			vs[i] = _mm256_load_ps(&neuronsV[i * 8]);
			ws[i] = _mm256_load_ps(&neuronsW[i * 8]);
			ins[i] = _mm256_load_ps(&neuronsIn[i * 8]);
		}

		static const __m256 div3 = [](void) -> __m256
		{
			float temp[]{ 3.f, 3.f, 3.f, 3.f, 3.f, 3.f, 3.f, 3.f };
			return _mm256_load_ps(temp);
		}();

		__m256 iextv = [&iext](void) -> __m256
		{
			float temp[]{ iext, iext, iext, iext, iext, iext, iext, iext };
			return _mm256_load_ps(temp);
		}();

		__m256 exprdtv = [&dt](void) -> __m256
		{
			float temp[]{ expr * dt, expr * dt, expr * dt, expr * dt, expr * dt, expr * dt, expr * dt, expr * dt };
			return _mm256_load_ps(temp);
		}();

		static const __m256 av = [](void) -> __m256
		{
			float temp[]{ a, a, a, a, a, a, a, a };
			return _mm256_load_ps(temp);
		}();

		static const __m256 bv = [](void) -> __m256
		{
			float temp[]{ b, b, b, b, b, b, b, b };
			return _mm256_load_ps(temp);
		}();

		__m256 thetadt = [&dt](void) -> __m256
		{
			float temp[]{ dt / theta, dt / theta, dt / theta, dt / theta, dt / theta, dt / theta, dt / theta, dt / theta };
			return _mm256_load_ps(temp);
		}();

		for (int i = 0; i < count / 8; ++i)
		{
			// vs += (vs - (vs * vs * vs) / 3.f - ws - iext - ins) * exprdtv
			__m256 nv = _mm256_mul_ps(vs[i], _mm256_mul_ps(vs[i], vs[i]));
			nv = _mm256_sub_ps(vs[i], _mm256_div_ps(nv, div3));
			nv = _mm256_sub_ps(nv, ws[i]);
			nv = _mm256_add_ps(nv, iextv);
			nv = _mm256_add_ps(nv, ins[i]);
			nv = _mm256_mul_ps(nv, exprdtv);
			vs[i] = _mm256_add_ps(vs[i], nv);

			// ws += (vs - av - ws * bv) * thetadt
			nv = _mm256_sub_ps(vs[i], av);
			nv = _mm256_sub_ps(nv, _mm256_mul_ps(ws[i], bv));
			ws[i] = _mm256_add_ps(ws[i], _mm256_mul_ps(nv, thetadt));
		}

		for (int i = 0; i < count / 8; ++i)
		{
			_mm256_storeu_ps(&neuronsV[i * 8], vs[i]);
			_mm256_storeu_ps(&neuronsW[i * 8], ws[i]);
		}
	}

	// scalar edition
	for (int i = 0; i < neuronsV.size() % 8; ++i)
	{
		auto off = neuronsV.size() - 1 - i;
		auto& v = neuronsV[off];
		auto& w = neuronsW[off];
		auto& in = neuronsIn[off];

		v += (v - (v * v * v) / 3.f - w - iext - in) * expr * dt;
		w += (v - a - w * b) * dt / theta;
	}

	std::ranges::fill(neuronsIn, 0.f);

#pragma once
#include <string_view>
#include "../codec.h"

inline bool has_error(std::string_view result) {
	msgpack_codec codec;
	auto tp = codec.unpack<std::tuple<int>>(result.data(), result.size());

	return std::get<0>(tp) != 0;
}

template<typename T>
inline T get_result(std::string_view result) {
	msgpack_codec codec;
	auto err_tp = codec.unpack<std::tuple<int, T>>(result.data(), result.size());
	return std::get<1>(err_tp);
}
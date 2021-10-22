---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/segment_map.test.cpp
    title: test/segment_map.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://satanic0258.github.io/snippets/data-structure/SegmentMap.html
  bundledCode: "#line 1 \"atcoder/segment_map.hpp\"\n\n\n\n#include <map>\n\nnamespace\
    \ atcoder {\n\n// https://satanic0258.github.io/snippets/data-structure/SegmentMap.html\n\
    \n// #### attention! : [l, r] ( include r, not [l, r) )\nclass SegmentMap : public\
    \ std::map<signed, signed> {\nprivate:\n    bool flagToMergeAdjacentSegment;\n\
    public:\n    // if merge [l, c] and [c+1, r], set flagToMergeAdjacentSegment to\
    \ true\n    SegmentMap(bool flagToMergeAdjacentSegment_) :\n            flagToMergeAdjacentSegment(flagToMergeAdjacentSegment_)\
    \ {}\n    // __exist -> iterator pair(l, r) (contain p)\n    // noexist -> map.end()\n\
    \    auto get(signed p) const {\n        auto it = upper_bound(p);\n        if\
    \ (it == begin() || (--it)->second < p) return end();\n        return it;\n  \
    \  }\n    // insert segment [l, r]\n    void insert(signed l, signed r) {\n  \
    \      auto itl = upper_bound(l), itr = upper_bound(r + flagToMergeAdjacentSegment);\n\
    \        if (itl != begin()) {\n            if ((--itl)->second < l - flagToMergeAdjacentSegment)\
    \ ++itl;\n        }\n        if (itl != itr) {\n            l = std::min(l, itl->first);\n\
    \            r = std::max(r, std::prev(itr)->second);\n            erase(itl,\
    \ itr);\n        }\n        (*this)[l] = r;\n    }\n    // remove segment [l,\
    \ r]\n    void remove(signed l, signed r) {\n        auto itl = upper_bound(l),\
    \ itr = upper_bound(r);\n        if (itl != begin()) {\n            if ((--itl)->second\
    \ < l) ++itl;\n        }\n        if (itl == itr) return;\n        int tl = std::min(l,\
    \ itl->first), tr = std::max(r, std::prev(itr)->second);\n        erase(itl, itr);\n\
    \        if (tl < l) (*this)[tl] = l - 1;\n        if (r < tr) (*this)[r + 1]\
    \ = tr;\n    }\n    // Is p and q in same segment?\n    bool same(signed p, signed\
    \ q) const {\n        const auto&& it = get(p);\n        return it != end() &&\
    \ it->first <= q && q <= it->second;\n    }\n};\n\n}  // namespace atcoder\n\n\
    \n"
  code: "#ifndef ATCODER_SEGMENT_MAP_HPP\n#define ATCODER_SEGMENT_MAP_HPP 1\n\n#include\
    \ <map>\n\nnamespace atcoder {\n\n// https://satanic0258.github.io/snippets/data-structure/SegmentMap.html\n\
    \n// #### attention! : [l, r] ( include r, not [l, r) )\nclass SegmentMap : public\
    \ std::map<signed, signed> {\nprivate:\n    bool flagToMergeAdjacentSegment;\n\
    public:\n    // if merge [l, c] and [c+1, r], set flagToMergeAdjacentSegment to\
    \ true\n    SegmentMap(bool flagToMergeAdjacentSegment_) :\n            flagToMergeAdjacentSegment(flagToMergeAdjacentSegment_)\
    \ {}\n    // __exist -> iterator pair(l, r) (contain p)\n    // noexist -> map.end()\n\
    \    auto get(signed p) const {\n        auto it = upper_bound(p);\n        if\
    \ (it == begin() || (--it)->second < p) return end();\n        return it;\n  \
    \  }\n    // insert segment [l, r]\n    void insert(signed l, signed r) {\n  \
    \      auto itl = upper_bound(l), itr = upper_bound(r + flagToMergeAdjacentSegment);\n\
    \        if (itl != begin()) {\n            if ((--itl)->second < l - flagToMergeAdjacentSegment)\
    \ ++itl;\n        }\n        if (itl != itr) {\n            l = std::min(l, itl->first);\n\
    \            r = std::max(r, std::prev(itr)->second);\n            erase(itl,\
    \ itr);\n        }\n        (*this)[l] = r;\n    }\n    // remove segment [l,\
    \ r]\n    void remove(signed l, signed r) {\n        auto itl = upper_bound(l),\
    \ itr = upper_bound(r);\n        if (itl != begin()) {\n            if ((--itl)->second\
    \ < l) ++itl;\n        }\n        if (itl == itr) return;\n        int tl = std::min(l,\
    \ itl->first), tr = std::max(r, std::prev(itr)->second);\n        erase(itl, itr);\n\
    \        if (tl < l) (*this)[tl] = l - 1;\n        if (r < tr) (*this)[r + 1]\
    \ = tr;\n    }\n    // Is p and q in same segment?\n    bool same(signed p, signed\
    \ q) const {\n        const auto&& it = get(p);\n        return it != end() &&\
    \ it->first <= q && q <= it->second;\n    }\n};\n\n}  // namespace atcoder\n\n\
    #endif  // ATCODER_SEGMENT_MAP_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/segment_map.hpp
  requiredBy: []
  timestamp: '2021-10-07 22:44:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segment_map.test.cpp
documentation_of: atcoder/segment_map.hpp
layout: document
redirect_from:
- /library/atcoder/segment_map.hpp
- /library/atcoder/segment_map.hpp.html
title: atcoder/segment_map.hpp
---

#include <rsl/rename>

#include <experimental/meta>

struct HasMemberWithRename {
  [[= rsl::rename("foo")]] int member;
  int other;
};

static_assert(extract<rsl::rename>(annotations_of(^^HasMemberWithRename::member)[0]) == rsl::rename("foo"));
static_assert(rsl::has_rename_annotation(^^HasMemberWithRename::member));
static_assert(!rsl::has_rename_annotation(^^HasMemberWithRename::other));


template<rsl::rename R>
consteval void foo()
{
    static_assert(R == rsl::rename("bar"));
    static_assert(R.name.data() == std::define_static_string("bar"));
}

consteval
{
    foo<rsl::rename("bar")>();
}

#pragma once

#include <nix/expr/eval-cache.hh>
#include <nix/flake/flake.hh>

namespace nix::eval_cache {

/**
 * Create an eval cache for a locked flake
 * Uses Nix's openEvalCache() which handles caching automatically
 */
inline ref<EvalCache> makeWorkerEvalCache(
    ref<EvalState> state,
    ref<const flake::LockedFlake> lockedFlake)
{
    return flake::openEvalCache(*state, lockedFlake);
}

} // namespace nix::eval_cache

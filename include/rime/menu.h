//
// Copyright RIME Developers
// Distributed under the BSD License
//
// 2011-05-29 GONG Chen <chen.sst@gmail.com>
//
#ifndef RIME_MENU_H_
#define RIME_MENU_H_

#include <functional>
#include <vector>
#include <rime/candidate.h>
#include <rime/common.h>

namespace rime {

struct Page {
  int page_size = 0;
  int page_no = 0;
  bool is_last_page = false;
  CandidateList candidates;
};

class Filter;
class MergedTranslation;
class Translation;

class Menu {
 public:
  Menu();

  void AddTranslation(shared_ptr<Translation> translation);
  void AddFilter(Filter* filter);

  size_t Prepare(size_t candidate_count);
  Page* CreatePage(size_t page_size, size_t page_no);
  shared_ptr<Candidate> GetCandidateAt(size_t index);

  // CAVEAT: returns the number of candidates currently obtained,
  // rather than the total number of available candidates.
  size_t candidate_count() const { return candidates_.size(); }

  bool empty() const;

 private:
  shared_ptr<MergedTranslation> merged_;
  shared_ptr<Translation> result_;
  CandidateList candidates_;
};

}  // namespace rime

#endif  // RIME_MENU_H_

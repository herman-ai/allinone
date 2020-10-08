'''
You are given a list of jobs to be done, where each job
is represented by a start time and end time.
Two jobs are compatible if they don't overlap.
Find the largest subset of compatible jobs.
For example, given the following jobs
(there is no guarantee that jobs will be sorted):
[(0, 6), (1, 4), (3, 5), (3, 8), (4, 7), (5, 9), (6, 10), (8, 11)] 
Return:  [(1, 4), (4, 7), (8, 11)]
'''

def is_compatible(job, jobs):
  for j in jobs:
    if j[0] < job[0]:
      j1 = j
      j2 = job
    else:
      j1=job
      j2=j
    if j1[1] > j2[0]:
      return False
  return True


def largest_set(jobs, compatible_jobs):
    if len(jobs) == 0:
      return compatible_jobs
    res = compatible_jobs
    for i, job in enumerate(jobs):
      if is_compatible(job, compatible_jobs):
        temp = largest_set(jobs[:i]+jobs[i+1:], compatible_jobs+[job])
        if len(temp) > len(res):
          res = temp
    return res


ans = largest_set([(0, 6), (1, 4), (3, 5), (3, 8), (4, 7), (5, 9), (6, 10), (8, 11)], [])
print(ans)


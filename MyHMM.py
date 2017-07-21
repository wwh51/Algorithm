def get_prob_last_state(obs, states, start_p, trans_p, emit_p):

  prob_states = {}
  prob_obs0 = sum([start_p[s] * emit_p[s][obs[0]] for s in states])
  for st in states:
    prob_states[st] = start_p[st] * emit_p[st][obs[0]] / prob_obs0
  print prob_states

  for i in range(1, len(obs)):
    prob_st = {}  # prob of state 
    for st in states:
      prob_st[st] = sum([prob_states[prev_state] * trans_p[prev_state][st] for prev_state in states ])
    prob_obs = sum([prob_st[s]*emit_p[s][obs[i]] for s in states])
    for st in states:
      prob_states[st] = prob_st[st] * emit_p[st][obs[i]] / prob_obs
    print prob_states

obs = ('walk', 'walk', 'home')
states = ('sunny', 'rainy')
start_p = {'sunny': 0.6, 'rainy': 0.4}
trans_p = {
   'sunny' : {'sunny': 0.7, 'rainy': 0.3},
   'rainy' : {'sunny': 0.4, 'rainy': 0.6}
   }
emit_p = {
   'sunny' : {'walk': 0.5, 'shopping': 0.4, 'home': 0.1},
   'rainy' : {'walk': 0.1, 'shopping': 0.3, 'home': 0.6}
   }
get_prob_last_state(obs,
                   states,
                   start_p,
                   trans_p,
                   emit_p)
      




def viterbi(obs, states, start_p, trans_p, emit_p):
    V = [{}]
    for st in states:
        V[0][st] = {"prob": start_p[st] * emit_p[st][obs[0]], "prev": None}
    # Run Viterbi when t > 0
    for t in range(1, len(obs)):
        V.append({})
        for st in states:
            max_tr_prob = max(V[t-1][prev_st]["prob"]*trans_p[prev_st][st] for prev_st in states)
            for prev_st in states:
                if V[t-1][prev_st]["prob"] * trans_p[prev_st][st] == max_tr_prob:
                    max_prob = max_tr_prob * emit_p[st][obs[t]]
                    V[t][st] = {"prob": max_prob, "prev": prev_st}
                    break

    # for t in range(1, len(obs)):
    #     V.append({})
    #     for st in states:
    #         max_prob = 0
    #         max_prev_st = None
    #         for prev_st in states:
    #           new_prob = V[t-1][prev_st]["prob"]*trans_p[prev_st][st]
    #           if(new_prob > max_prob):
    #             max_prob = new_prob
    #             V[t][st] = {"prob": max_prob * emit_p[st][obs[t]], "prev": prev_st}


    for line in dptable(V):
        print line
    opt = []
    for vv in V:
      print '------------------------------'
      print vv


    # The highest probability
    max_prob = max(value["prob"] for value in V[-1].values())
    previous = None
    # Get most probable state and its backtrack
    for st, data in V[-1].items():
        if data["prob"] == max_prob:
            opt.append(st)
            previous = st
            break
    # Follow the backtrack till the first observation
    for t in range(len(V) - 2, -1, -1):
        opt.insert(0, V[t + 1][previous]["prev"])
        previous = V[t + 1][previous]["prev"]

    print 'The steps of states are ' + ' '.join(opt) + ' with highest probability of %s' % max_prob

def dptable(V):
    # Print a table of steps from dictionary
    yield " ".join(("%12d" % i) for i in range(len(V)))
    for state in V[0]:
        yield "%.7s: " % state + " ".join("%.7s" % ("%f" % v[state]["prob"]) for v in V) 



# viterbi(obs,
#                    states,
#                    start_p,
#                    trans_p,
#                    emit_p)

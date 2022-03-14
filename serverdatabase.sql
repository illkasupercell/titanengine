ttt as (
                    select o.tovarid, o.edizmerid, o.cena, 
                           o.vos, o.cena*o.vos as sum_vos,  
                           coalesce(p.sum_kl,0.0)  as _prih_kl, coalesce( p.sum_prih,0.0) as  sum_prih, 
                           coalesce( p.sum_prih_docs,0.0) as  sum_prih_docs,
                           coalesce(r.sum_kl,0.0) as _rash_kl, coalesce(r.sum_rash,0.0)  as  sum_rash ,
                           coalesce(r.sum_rash_docs,0.0)  as  sum_rash_docs ,
                           coalesce(rd.sum_kl,0.0) as _rash_doc_kl, coalesce(rd.sum_rash_doc,0.0) as sum_rash_doc, 
                           coalesce(rd.sum_rash_doc_docs, 0.0) as sum_rash_doc_docs ,
                 --          coalesce(rs.sum_kl,0.0) as _rash_storno_kl, coalesce(rs.sum_rash,0.0) as sum_rash_storno ,
                           o.ostid, o.ss, o.sb 
                    from ost_ o
                    left join prih p on (o.tovarid = p.tovarid 
                                     and o.edizmerid=p.edizmerid
                                     and o.ss = p.ss
                                     and o.sb = p.sb)   
                    left join rash r on (o.tovarid =r.tovarid 
                                     and o.edizmerid=r.edizmerid
                                     and o.ss = r.ss
                                     and o.sb = r.sb) 
                    left join rash_doc rd on (o.tovarid =rd.tovarid 
                                          and o.edizmerid=rd.edizmerid
                                          and o.ss = rd.ss_
                                          and o.sb = rd.sb_) 
                   -- left join rash_old_072018 ro on (o.tovarid =ro.tovarid 
                                      --    and o.edizmerid=ro.edizmerid) 
              -- 08.2018     left join rash_storno rs on (o.tovarid =rs.tovarid    and o.edizmerid=rs.edizmerid) 
--                    where   o.vos+p.sum_kl>0  
                  ),
                tt as (    
                  select *, ttt.vos + ttt._prih_kl - ttt._rash_kl as ost_fact ,
--                    case when  (ttt.vos+ttt._prih_kl<>0 )  then
--                        ( ttt.sum_vos+ttt.sum_prih -ttt.sum_rash_storno)/(ttt.vos+ttt._prih_kl-ttt._rash_storno_kl)
--                      else ttt.cena end   as new_cen from ttt
          --          case when  (ttt.vos+ttt._prih_kl+ttt._rash_storno_kl-ttt._rash_kl-ttt._rash_doc_kl<>0 )  then
          --              ( ttt.sum_vos+ttt.sum_prih +ttt.sum_rash_storno-ttt.sum_rash-ttt.sum_rash_doc)/(ttt.vos+ttt._prih_kl-ttt._rash_storno_kl-ttt._rash_kl-ttt._rash_doc_kl)
                         case when (ttt.vos+ttt._prih_kl-ttt._rash_kl-ttt._rash_doc_kl<>0 ) then
                           ( ttt.sum_vos+ttt.sum_prih -ttt.sum_rash-ttt.sum_rash_doc)/(ttt.vos+ttt._prih_kl-ttt._rash_kl-ttt._rash_doc_kl)
                         else ttt.cena end as new_cen 
                  from ttt
                )        
      select tt.tovarid,
             tt.cena,
             tt.edizmerid,
             t.kt,
             t.nt,
             tt.vos,
             round(sum_vos,2), 
             u.name_u,
             tt._prih_kl as _prih_kl, 
      --       round( tt.sum_prih,2)  as sum_prih ,
              tt.sum_prih_docs  as sum_prih ,
             tt._rash_kl as _rash_kl, 
       --      round( tt.sum_rash,2)  as sum_rash ,
             tt.sum_rash_docs  as sum_rash ,
             tt.ost_fact,
--             round(tt.ost_fact* tt.new_cen,5),
             round(tt.ost_fact* tt.new_cen,2),
             t.priz,
             round(tt.new_cen,5),
             tt.ostid,
             tt._rash_doc_kl,
--             tt.sum_rash_doc,
             tt.sum_rash_doc_docs,
             t.dk_2010,
             coalesce( tt.ss, '0'),
             coalesce( tt.sb, '0')
          from tt
          left join material.tovar t on (t.tovarid=tt.tovarid)
          left join nsi.units u  on (u.id=tt.edizmerid);

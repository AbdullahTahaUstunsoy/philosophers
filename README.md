Bu proje, bir masa etrafında oturan ve sadece yemek yiyen, düşünen veya uyuyan filozofların simülasyonudur. Amacı, **multi-threading** (çoklu iş parçacığı) kullanarak paylaşılan kaynakların (çatallar) yönetimini sağlamak ve filozofların açlıktan ölmesini engellemektir.

---

## Özellikler

- **Multi-threading:** Her bir filozofun kendi iş parçacığında (thread) çalışması.
- **Mutex Yönetimi:** Çatalların (paylaşılan kaynaklar) güvenli kullanımı için `pthread_mutex` kullanımı.
- **Hassas Zamanlama:** Milisaniye hassasiyetinde simülasyon takibi ve ölüm kontrolü.
- **Veri Yarışı (Data Race) Önleme:** Tüm paylaşılan değişkenlerin mutex'lerle korunması.
- **Esnek Parametreler:** Farklı filozof sayıları ve zaman limitleri ile simülasyon testi.

---

## Teknik Kazanımlar

Bu proje süresince şu sistem programlama yetkinliklerini geliştirdim:
- **Thread Senkronizasyonu:** `pthread_create` ve `pthread_join` ile iş parçacıklarının yaşam döngüsünü yönetme.
- **Kritik Bölüm (Critical Section) Yönetimi:** Paylaşılan veriye erişimi senkronize ederek tutarlılığı sağlama.
- **Deadlock & Race Condition Çözümleri:** Kilitlenme durumlarını analiz etme ve `Valgrind --tool=helgrind` ile veri yarışlarını tespit etme.
- **Performans Optimizasyonu:** CPU kullanımını minimize ederek verimli bir simülasyon döngüsü kurma.

---

##Kurulum ve Çalıştırma

1. **Depoyu klonlayın:**
   ```bash
   git clone [https://github.com/AbdullahTahaUstunsoy/philosophers.git](https://github.com/AbdullahTahaUstunsoy/philosophers.git)
   cd philosophers/philo
2. Derleme yapın: make
3. Simülasyonu başlatın: ./philo [filozof_sayısı] [ölüm_süresi] [yemek_süresi] [uyku_süresi] [opsiyonel: yemek_sayısı]

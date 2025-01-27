# PgPool-II: High-performance pooling and load balancing for PostgreSQL

Pgpool-II is a middleware that works between PostgreSQL servers and a PostgreSQL database client.

## Features

|    Features              |Description                               |
|--------------------------|---------------------------------------|
|**Connection Pooling**.   |Pgpool-II improves system performance by saving and reusing connections to PostgreSQL servers based on their similar connection parameters.|
|**Replication**           |Pgpool-II can manage multiple PostgreSQL servers and use replication to create real-time backups for high availability.|
|**Load Balancing**        |Pgpool-II leverages PostgreSQL replication to distribute SELECT queries across multiple PostgreSQL servers, improving overall system performance in high-traffic environments.|
|**Limiting Exceeding Connections**         |PostgreSQL has a connection limit, PgPool-II queues extra connections instead of rejecting them, potentially increasing system performance.|
|**Watchdog**              |This feature helps to manages multiple Pgpool-II instances to create a highly available cluster system|
|**In Memory Query Cache** |Pgpool-II uses an in-memory query cache to store and reuse SELECT query results|

Homepage: [https://www.pgpool.net/](https://www.pgpool.net/)

Latest Documentation: [English](https://www.pgpool.net/docs/latest/en/html/index.html) | [日本語](https://www.pgpool.net/docs/latest/ja/html/index.html)

## Building from git

```
$ git clone https://github.com/pgpool/pgpool2.git
$ cd pgpool2
$ autoreconf -fi
$ ./configure
$ make
$ make install
```

## Production deployment

### Installation
Install the repository corresponding to your Pgpool-II version
```
dnf install https://www.pgpool.net/yum/rpms/4.5/redhat/rhel-8-x86_64/pgpool-II-release-4.5-1.noarch.rpm
```
Then, install Pgpool-II.
```
dnf install pgpool-II-pg16
```
Please visit [Yum Repository](https://www.pgpool.net/mediawiki/index.php/Yum_Repository) and [APT Repository](https://www.pgpool.net/mediawiki/index.php/Apt_Repository) for more details

###  Configuration
All the Pgpool-II configuration files are installed in /etc/pgpool-II. For detailed documentation please refer to [Configuration Section](https://www.pgpool.net/docs/latest/en/html/configuring-pgpool.html)

###  Starting/stopping Pgpool-II
```
systemctl enable pgpool.service
```
```
systemctl start pgpool.service
```
```
systemctl stop pgpool.service
```
## License
PgPool-II is distributed under a license similar to BSD and MIT

## Contributing
Please join [pgpool-hackers mailing lis](https://www.pgpool.net/mailman/listinfo/pgpool-hackers) for new features development discussion. [more details](https://www.pgpool.net/mediawiki/index.php/Development)
